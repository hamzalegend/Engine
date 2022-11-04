#include "GL/glew.h"


#include "Jaguar/Log/log.h"
// #include "../Shader.h"

#include "TextureGL.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_img.h"

namespace Jaguar {

    TextureGL::TextureGL(std::string path, int Index, bool istransparent)
        :m_Index(Index)
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
        unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

        int imageType = istransparent ? GL_RGBA : GL_RGB;
        

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
    TextureGL::~TextureGL()
    {
    }
}