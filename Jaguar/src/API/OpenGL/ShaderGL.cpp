
#include "GL/glew.h"
#include "ShaderGL.h"
#include "../../Jaguar/Log/log.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>



namespace Jaguar{

    ShaderGL::ShaderGL(const char* vertexPath, const char* fragmentPath)
    {
        std::string vertexCode;
        std::string fragmentCode;
    
        // ensure ifstream objects can throw exceptions:
        vertexCode = Read(vertexPath);
        fragmentCode = Read(fragmentPath);
        
        vCode = vertexCode.c_str();
        fCode = fragmentCode.c_str();
    
    
        Compile();
        
    }
    
    std::string ShaderGL::Read(std::string filePath)
    {
        std::ifstream file;
        std::string code;
    
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    
        try
        {
            // open files
            file.open(filePath);
            
            std::stringstream stream;
            // read file's buffer contents into streams
            stream << file.rdbuf();
            
            // close file handlers
            file.close();
            
            // convert stream into string
            code = stream.str();
            
        }
        catch (std::ifstream::failure e)
        {
            JR_CORE_ERROR("could not successfuly read the shaderFile");
            assert(0);
            return nullptr;
        }
        return code;
       
    }
    
    void ShaderGL::Compile()
    {
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];
    
        // vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vCode, NULL);
        glCompileShader(vertex);
        // print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            JR_CORE_ERROR("Error compiling vertex shader \"{0}\"", infoLog);
            return;
        };
    
        // similiar for Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fCode, NULL);
        glCompileShader(fragment);
        // print compile errors if any
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            JR_CORE_ERROR("Error compiling fragment shader \"{0}\"", infoLog);
        };
    
        // shader Program
        m_ID = glCreateProgram();
        glAttachShader(m_ID, vertex);
        glAttachShader(m_ID, fragment);
        glLinkProgram(m_ID);
        // print linking errors if any
        glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
            JR_CORE_ERROR("Error compiling & linking shader program \"{0}\"", infoLog);
            return;
        }
    
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    
        // Bind();
        
    }
    
    void ShaderGL::Bind() const
    {
        glUseProgram(m_ID);
    }
    
    void ShaderGL::UnBind() const
    {
        glUseProgram(0);
    }

    ShaderGL::~ShaderGL()
    {
        glDeleteProgram(m_ID);
    }
}