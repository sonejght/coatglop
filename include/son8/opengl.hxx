/* Ⓒ 2023 - Sonejght */
#pragma once

#include <glad/gl.h>
#include <array>
#include <vector>
#include <set>
#include <type_traits>
#include <cassert>

# ifndef          SON8OPENGL_DEFINED
# define          SON8OPENGL_DEFINED
# define          SON8OPENGL_INCLUDE
# define      SON8OPENGL_VERSION_1_1
# define      SON8OPENGL_VERSION_1_5
# define      SON8OPENGL_VERSION_2_1
# define      SON8OPENGL_VERSION_3_3
# define      SON8OPENGL_VERSION_4_3
# define     SON8OPENGL_PROFILE_CORE
# define SON8OPENGL_VERSION 0x0403CE
#  endif       // SON8OPENGL_DEFINED

namespace son8::opengl::enums
{
    enum class Bool : unsigned
    {
        False = GL_FALSE,
        True = GL_TRUE,
    };

    enum class Error : GLenum
    {
        None = GL_NO_ERROR,
        Enum = GL_INVALID_ENUM,
        Value = GL_INVALID_VALUE,
        Operation = GL_INVALID_OPERATION,
        Memory = GL_OUT_OF_MEMORY,
#ifndef SON8OPENGL_PROFILE_CORE
        Overflow = GL_STACK_OVERFLOW,
        Underflow = GL_STACK_UNDERFLOW,
#endif
    };

    enum class Clear : GLbitfield
    {
        Colorbit = GL_COLOR_BUFFER_BIT,
        Depthbit = GL_DEPTH_BUFFER_BIT,
        Stencilbit = GL_STENCIL_BUFFER_BIT,
#ifndef SON8OPENGL_PROFILE_CORE
        AccumBit = GL_ACCUM_BUFFER_BIT,
        All = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT,
#else
        All = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT,
#endif
    };

    enum class Draw : GLenum
    {
        Default = GL_TRIANGLES,
        Strip = GL_TRIANGLE_STRIP,
        Fan = GL_TRIANGLE_FAN,
        Lines = GL_LINES,
        StripLine = GL_LINE_STRIP,
        Loop = GL_LINE_LOOP,
        Points = GL_POINTS,
#ifdef SON8OPENGL_VERSION_3_3
        Adjacency = GL_TRIANGLES_ADJACENCY,
        AdjacencyStrip = GL_TRIANGLE_STRIP_ADJACENCY,
        AdjacencyLines = GL_LINES_ADJACENCY,
        AdjacencyStripLine = GL_LINE_STRIP_ADJACENCY,
#endif
#ifdef SON8OPENGL_VERSION_4_3
        Patches = GL_PATCHES,
#endif
#ifndef SON8OPENGL_PROFILE_CORE
        Polygon = GL_POLYGON,
        Quads = GL_QUADS,
        StripQuad = GL_QUAD_STRIP,
#endif
    };

    enum class Capability : GLenum
    {
        Depth = GL_DEPTH_TEST,
        Cull = GL_CULL_FACE,
#ifndef SON8OPENGL_PROFILE_CORE
        Normalize = GL_NORMALIZE,
        PointSmooth = GL_POINT_SMOOTH,
#endif
    };

#ifdef SON8OPENGL_VERSION_1_5
    enum class Buffer : GLenum
    {
        Array = GL_ARRAY_BUFFER,
        Element = GL_ELEMENT_ARRAY_BUFFER,
    };

    enum class Usage : GLenum
    {
        StaticDraw = GL_STATIC_DRAW,
    };
#endif

#ifdef SON8OPENGL_VERSION_2_1
    enum class Shader : GLenum
    {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
#   ifdef SON8OPENGL_VERSION_3_3
        Geometry = GL_GEOMETRY_SHADER,
#   endif
    };
#endif

#ifndef SON8OPENGL_PROFILE_CORE
    enum class Array : GLenum
    {
        Vertex = GL_VERTEX_ARRAY,
        Color = GL_COLOR_ARRAY,
        Normal = GL_NORMAL_ARRAY,
        Texture = GL_TEXTURE_COORD_ARRAY,
        Edge = GL_EDGE_FLAG_ARRAY,
        Index = GL_INDEX_ARRAY,
    };

    enum class Matrix : GLenum
    {
        Projection = GL_PROJECTION,
        ModelView = GL_MODELVIEW,
    };

    enum class List : GLenum
    {
        Compile = GL_COMPILE,
        Execute = GL_COMPILE_AND_EXECUTE,
    };
#endif
}

namespace son8::opengl::types
{
    using array2i = std::array< GLint, 2 >;
    using array2s = std::array< GLshort, 2 >;
    using array2f = std::array< GLfloat, 2 >;
    using array2d = std::array< GLdouble, 2 >;

    using array3i = std::array< GLint, 3 >;
    using array3b = std::array< GLbyte, 3 >;
    using array3s = std::array< GLshort, 3 >;
    using array3f = std::array< GLfloat, 3 >;
    using array3d = std::array< GLdouble, 3 >;

    using array4i = std::array< GLint, 4 >;
    using array4b = std::array< GLbyte, 4 >;
    using array4s = std::array< GLshort, 4 >;
    using array4f = std::array< GLfloat, 4 >;
    using array4d = std::array< GLdouble, 4 >;

    using array3ui = std::array< GLuint, 3 >;
    using array3ub = std::array< GLubyte, 3 >;
    using array3us = std::array< GLushort, 3 >;

    using array4ui = std::array< GLuint, 4 >;
    using array4ub = std::array< GLubyte, 4 >;
    using array4us = std::array< GLushort, 4 >;

    using array16f = std::array< GLfloat, 16 >;
    using array16d = std::array< GLdouble, 16 >;

    struct List
    {
        GLuint list;
        List() noexcept { }
        List(GLuint u) noexcept : list(u) {  }
        operator GLuint() const noexcept { return list; }
    };

    using vectorList = std::vector< List >;

    template< typename T >
    struct Elements
    {
        using value_type = typename T::value_type;
        void *indices;
        std::size_t count;
        GLuint index;
        enums::Draw draw;
        Elements() = delete;
        Elements(T &data, enums::Draw draw) noexcept : indices(data.data()), count(data.size()), draw(draw) {  }
        constexpr GLenum t() const noexcept
        {
            static_assert(std::is_integral_v< value_type >);
            static_assert(!std::is_signed_v< value_type >);
            constexpr auto value_size = sizeof(value_type);
            static_assert(1 <= value_size && value_size <= 4);
            if constexpr (value_size == 1) return GL_UNSIGNED_BYTE;
            if constexpr (value_size == 2) return GL_UNSIGNED_SHORT;
            return GL_UNSIGNED_INT;
        }
        GLsizei size() const noexcept
        {
            return count * sizeof(value_type);
        }
    };
#ifdef SON8OPENGL_VERSION_2_1
    struct Shader
    {
        GLuint index;
        enums::Shader type;
        Shader() = delete;
        Shader(enums::Shader type, GLuint index = 0) noexcept : index(index) { }
        operator GLuint() const noexcept { assert(index != 0); return index; }
        operator enums::Shader() const noexcept { return type; }
    };

    struct Program
    {
        GLuint id;
        std::set< GLint > attributes;
        Program() = delete;
        Program(GLuint id) noexcept : id(id) { }
        operator GLuint() const noexcept { assert(id != 0); return id; }
    };
#endif
}

#ifdef SON8OPENGL_INCLUDE
#include "opengl-1_1.hxx"
#include "opengl-1_5.hxx"
#include "opengl-2_1.hxx"
#include "opengl-3_3.hxx"
#include "opengl-4_3.hxx"
#endif
