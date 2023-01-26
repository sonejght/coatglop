/* Ⓒ 2023 - Sonejght */
#pragma once

# ifndef          SON8OPENGL_DEFINED
# define          SON8OPENGL_DEFINED
# define      SON8OPENGL_VERSION_1_1
# define      SON8OPENGL_VERSION_1_5
# define      SON8OPENGL_VERSION_2_1
# define     SON8OPENGL_PROFILE_NONE
# define SON8OPENGL_VERSION 0x020100
#include            "opengl-1_1.hxx"
#include            "opengl-1_5.hxx"
#  endif       // SON8OPENGL_DEFINED

#include "opengl.hxx"

namespace son8::opengl
{
    // Vertex speicfication part


    // Shader specification part
    inline auto CreateShader(enums::Shader type) { return types::Shader(type, glCreateShader(static_cast< GLenum >(type))); }
    inline auto DeleteShader(types::Shader shader) { glDeleteShader(shader); }
    inline auto ShaderSource(types::Shader shader, char const *cstr) { glShaderSource(shader, 1, &cstr, nullptr); }
    inline auto CompileShader(types::Shader shader) { glCompileShader(shader); }
}
