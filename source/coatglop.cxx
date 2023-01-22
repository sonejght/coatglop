/* Ⓒ 2023 - Sonejght */
#include <son8/opengl-4_3-comp.hxx>
#include <cassert>

namespace son8::opengl
{
    enums::Error GetError()
    {
        auto err = static_cast< enums::Error >(glGetError());
        assert(err == enums::Error::None);
        return err;
    }
}

