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

    template< typename T >
    inline auto DrawElements(types::Elements< T > const &elems) { glDrawElements(elems.draw, elems.count, elems.t(), elems.indices); }

// Compatibility profile functionality
#ifndef SON8OPENGL_PROFILE_CORE
    // Vertex specification part
    inline auto EnableClientState(enums::Array array) { glEnableClientState(static_cast< GLenum >(array)); }
    inline auto DisableClientState(enums::Array array) { glDisableClientState(static_cast< GLenum >(array)); }

    inline auto Begin() { glBegin(static_cast< GLenum >(enums::Draw::Default)); }
    inline auto Begin(enums::Draw mode) { glBegin(static_cast< GLenum >(mode)); }
    inline auto End() { glEnd(); }

    inline auto Vertex(types::array2s const &coords) { glVertex2sv(coords.data()); }
    inline auto Vertex(types::array2i const &coords) { glVertex2iv(coords.data()); }
    inline auto Vertex(types::array2f const &coords) { glVertex2fv(coords.data()); }
    inline auto Vertex(types::array2d const &coords) { glVertex2dv(coords.data()); }
    inline auto Vertex(types::array3s const &coords) { glVertex3sv(coords.data()); }
    inline auto Vertex(types::array3i const &coords) { glVertex3iv(coords.data()); }
    inline auto Vertex(types::array3f const &coords) { glVertex3fv(coords.data()); }
    inline auto Vertex(types::array3d const &coords) { glVertex3dv(coords.data()); }
    inline auto Vertex(types::array4s const &coords) { glVertex4sv(coords.data()); }
    inline auto Vertex(types::array4i const &coords) { glVertex4iv(coords.data()); }
    inline auto Vertex(types::array4f const &coords) { glVertex4fv(coords.data()); }
    inline auto Vertex(types::array4d const &coords) { glVertex4dv(coords.data()); }
    inline auto Vertex(GLint x, GLint y) { glVertex2i(x, y); }
    inline auto Vertex(GLshort x, GLshort y) { glVertex2s(x, y); }
    inline auto Vertex(GLfloat x, GLfloat y) { glVertex2f(x, y); }
    inline auto Vertex(GLdouble x, GLdouble y) { glVertex2d(x, y); }
    inline auto Vertex(GLint x, GLint y, GLint z) { glVertex3i(x, y, z); }
    inline auto Vertex(GLshort x, GLshort y, GLshort z) { glVertex3s(x, y, z); }
    inline auto Vertex(GLfloat x, GLfloat y, GLfloat z) { glVertex3f(x, y, z); }
    inline auto Vertex(GLdouble x, GLdouble y, GLdouble z) { glVertex3d(x, y, z); }
    inline auto Vertex(GLint x, GLint y, GLint z, GLint w) { glVertex4i(x, y, z, w); }
    inline auto Vertex(GLshort x, GLshort y, GLshort z, GLshort w) { glVertex4s(x, y, z, w); }
    inline auto Vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { glVertex4f(x, y, z, w); }
    inline auto Vertex(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { glVertex4d(x, y, z, w); }

    inline auto Color(types::array3i const &components) { glColor3iv(components.data()); }
    inline auto Color(types::array3b const &components) { glColor3bv(components.data()); }
    inline auto Color(types::array3s const &components) { glColor3sv(components.data()); }
    inline auto Color(types::array3f const &components) { glColor3fv(components.data()); }
    inline auto Color(types::array3d const &components) { glColor3dv(components.data()); }
    inline auto Color(types::array4i const &components) { glColor4iv(components.data()); }
    inline auto Color(types::array4b const &components) { glColor4bv(components.data()); }
    inline auto Color(types::array4s const &components) { glColor4sv(components.data()); }
    inline auto Color(types::array4f const &components) { glColor4fv(components.data()); }
    inline auto Color(types::array4d const &components) { glColor4dv(components.data()); }
    inline auto Color(types::array3ui const &components) { glColor3uiv(components.data()); }
    inline auto Color(types::array3ub const &components) { glColor3ubv(components.data()); }
    inline auto Color(types::array3us const &components) { glColor3usv(components.data()); }
    inline auto Color(types::array4ui const &components) { glColor4uiv(components.data()); }
    inline auto Color(types::array4ub const &components) { glColor4ubv(components.data()); }
    inline auto Color(types::array4us const &components) { glColor4usv(components.data()); }
    inline auto Color(GLint r, GLint g, GLint b) { glColor3i(r, g, b); }
    inline auto Color(GLbyte r, GLbyte g, GLbyte b) { glColor3b(r, g, b); }
    inline auto Color(GLuint r, GLuint g, GLuint b) { glColor3ui(r, g, b); }
    inline auto Color(GLshort r, GLshort g, GLshort b) { glColor3s(r, g, b); }
    inline auto Color(GLfloat r, GLfloat g, GLfloat b) { glColor3f(r, g, b); }
    inline auto Color(GLubyte r, GLubyte g, GLubyte b) { glColor3ub(r, g, b); }
    inline auto Color(GLdouble r, GLdouble g, GLdouble b) { glColor3d(r, g, b); }
    inline auto Color(GLushort r, GLushort g, GLushort b) { glColor3us(r, g, b); }
    inline auto Color(GLint r, GLint g, GLint b, GLint a) { glColor4i(r, g, b, a); }
    inline auto Color(GLbyte r, GLbyte g, GLbyte b, GLbyte a) { glColor4b(r, g, b, a); }
    inline auto Color(GLuint r, GLuint g, GLuint b, GLuint a) { glColor4ui(r, g, b, a); }
    inline auto Color(GLshort r, GLshort g, GLshort b, GLshort a) { glColor4s(r, g, b, a); }
    inline auto Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) { glColor4f(r, g, b, a); }
    inline auto Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a) { glColor4ub(r, g, b, a); }
    inline auto Color(GLdouble r, GLdouble g, GLdouble b, GLdouble a) { glColor4d(r, g, b, a); }
    inline auto Color(GLushort r, GLushort g, GLushort b, GLushort a) { glColor4us(r, g, b, a); }

    // Matrix specification part
    inline auto MatrixMode(enums::Matrix mode) { glMatrixMode(static_cast< GLenum >(mode)); }
    inline auto LoadIdentity() { glLoadIdentity(); }
    inline auto Ortho(GLdouble xl, GLdouble xr, GLdouble yb, GLdouble yt, GLdouble zn, GLdouble zf) { glOrtho(xl, xr, yb, yt, zn, zf); }
    inline auto Frustum(GLdouble xl, GLdouble xr, GLdouble yb, GLdouble yt, GLdouble zn, GLdouble zf) { glFrustum(xl, xr, yb, yt, zn, zf); }
    inline auto LoadMatrix(types::array16f const &mat) { glLoadMatrixf(mat.data()); }
    inline auto LoadMatrix(types::array16d const &mat) { glLoadMatrixd(mat.data()); }
    inline auto Scale(GLfloat x, GLfloat y, GLfloat z) { glScalef(x, y, z); }
    inline auto Scale(GLdouble x, GLdouble y, GLdouble z) { glScaled(x, y, z); }
    inline auto Translate(GLfloat x, GLfloat y, GLfloat z) { glTranslatef(x, y, z); }
    inline auto Translate(GLdouble x, GLdouble y, GLdouble z) { glTranslated(x, y, z); }
    inline auto Rotate(GLfloat degrees, GLfloat x, GLfloat y, GLfloat z) { glRotatef(degrees, x, y, z); }
    inline auto Rotate(GLdouble degrees, GLdouble x, GLdouble y, GLdouble z) { glRotated(degrees, x, y, z); }
    inline auto PushMatrix() { glPushMatrix(); }
    inline auto PopMatrix() { glPopMatrix(); }

    // List specification part
    types::vectorList GenLists(GLsizei s);
    void DeleteLists(types::vectorList &lists);
    void CallLists(types::vectorList const &lists);
    inline auto NewList(types::List list) { glNewList(list, static_cast< GLenum >(enums::List::Compile)); }
    inline auto NewList(types::List list, enums::List mode) { glNewList(list, static_cast< GLenum >(mode)); }
    inline auto EndList() { glEndList(); }
    inline auto CallList(types::List list) { glCallList(list); }
    inline auto IsList(types::List list) { return glIsList(list); }

#endif
}
