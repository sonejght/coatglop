/* Ⓒ 2023 - Sonejght */
#pragma once

#ifndef          SON8OPENGL_DEFINED
#define          SON8OPENGL_DEFINED
#define      SON8OPENGL_VERSION_1_1
#define     SON8OPENGL_PROFILE_NONE
#define SON8OPENGL_VERSION 0x010100
# endif       // SON8OPENGL_DEFINED

#include "opengl.hxx"

namespace son8::opengl
{
    // Essential specification part
    enums::Error GetError();
    inline auto Viewport() { glViewport(0, 0, 640, 480); }
    inline auto Viewport(GLsizei width, GLsizei height) { glViewport(0, 0, width, height); }
    inline auto Viewport(GLint x, GLint y, GLsizei width, GLsizei height) { glViewport(x, y, width, height); }

    inline auto Clear() { glClear(static_cast< GLbitfield >(enums::Clear::All)); }
    inline auto Clear(enums::Clear mask) { glClear(static_cast< GLbitfield >(mask)); }

    inline auto ClearColor() { glClearColor(0.f, 0.f, 0.f, 1.f); }
    inline auto ClearColor(GLfloat rgb) { glClearColor(rgb, rgb, rgb, 1.f); }
    inline auto ClearColor(GLfloat rgb, GLfloat a) { glClearColor(rgb, rgb, rgb, a); }
    inline auto ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) { glClearColor(r, g, b, a); }

    inline auto Enable(enums::Capability capability) { glEnable(static_cast< GLenum >(capability)); }
    inline auto Disable(enums::Capability capability) { glDisable(static_cast< GLenum >(capability)); }

    inline auto Flush() { glFlush(); }
    inline auto Finish() { glFinish(); }

    // Vertex specification part
    inline auto DrawArrays(GLsizei count) { glDrawArrays(static_cast< GLenum >(enums::Draw::Default), 0, count); }
    inline auto DrawArrays(enums::Draw mode, GLsizei count) { glDrawArrays(static_cast< GLenum >(mode), 0, count); }

// Compatibility profile functionality
#ifndef SON8OPENGL_PROFILE_CORE
    // Vertex specification part
    inline auto Begin() { glBegin(static_cast< GLenum >(enums::Draw::Default)); }
    inline auto Begin(enums::Draw mode) { glBegin(static_cast< GLenum >(mode)); }
    inline auto End() { glEnd(); }
#endif
}
