/* Ⓒ 2023 - Sonejght */
#pragma once

# ifndef          SON8OPENGL_DEFINED
# define          SON8OPENGL_DEFINED
# define      SON8OPENGL_VERSION_1_1
# define      SON8OPENGL_VERSION_1_5
# define     SON8OPENGL_PROFILE_NONE
# define SON8OPENGL_VERSION 0x010500
#include            "opengl-1_1.hxx"
#  endif       // SON8OPENGL_DEFINED

#include "opengl.hxx"

namespace son8::opengl
{
    // Buffer specification
    template< typename T >
    void GenBuffers(types::Elements< T > &elems) { glGenBuffers(1, &elems.index); }
    template< typename T >
    void DeleteBuffers(types::Elements< T > &elems) { glDeleteBuffers(1, &elems.index); }
    template< typename T >
    void BindBuffer(types::Elements< T > const &elems) { glBindBuffer(static_cast< GLenum >(enums::Buffer::Element), elems.index); }
    template< typename T >
    void BufferData(types::Elements< T > &elems) { glBufferData(GL_ELEMENT_ARRAY_BUFFER, elems.count * sizeof(T::value_type), elems.indices, GL_STATIC_DRAW); }
}
