#include "GL/glew.h"


#include "Jaguar/Log/log.h"
// #include "../Shader.h"

#include "TextureGL.h"

// #define STB_IMAGE_IMPLEMENTATION
        
        #include <iostream>
        #include <string>
        #include <filesystem>
#include "stb_Image/stb_img.h"

namespace Jaguar {

    TextureGL::TextureGL(std::string path, int Index, bool istransparent)
        :m_Index(Index), m_path(path)
    {
        // init
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_set_flip_vertically_on_load(true);
        // create
        glGenTextures(1, &m_ID);
        glActiveTexture(GL_TEXTURE0 + Index);
        glBindTexture(GL_TEXTURE_2D, m_ID);
        // load
        int width, height, nrChannels;
        unsigned char* data = stbi_load(m_path.c_str(), &width, &height, &nrChannels, 0);
        
        int imageType = istransparent ? GL_RGBA : GL_RGB;
        // #include <unistd.h>

        
        
        // using std::filesystem::current_path;

        char tmp[256];
        getcwd(tmp, 256);
        // JR_CORE_TRACE(tmp);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, imageType, width, height, 0, imageType, GL_UNSIGNED_BYTE, data); // TODO : add GL_RGBA
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            JR_CORE_ERROR("Failed to load texture");
            assert(0);
            return;
        }
        stbi_image_free(data);
        
    }

    void TextureGL::Bind() const
    {
        glActiveTexture(GL_TEXTURE0 + m_Index);
        glBindTexture(GL_TEXTURE_2D, m_ID);
    }
    void TextureGL::UnBind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    TextureGL::~TextureGL()
    {
    }
}