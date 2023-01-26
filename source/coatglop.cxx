/* Ⓒ 2023 - Sonejght */
#include <son8/opengl-4_3-comp.hxx>
#include <cassert>
#include <algorithm>
#include <numeric>

namespace son8::opengl
{
    enums::Error GetError()
    {
        auto err = static_cast< enums::Error >(glGetError());
        assert(err == enums::Error::None);
        return err;
    }

    types::vectorList GenLists(GLsizei s)
    {
        assert(s > 0);
        auto gen = glGenLists(s);
        assert(gen != 0);
        types::vectorList lists(s);
        std::iota(lists.begin(), lists.end(), gen);

        return lists;
    }

    void DeleteLists(types::vectorList& lists)
    {
        std::for_each(lists.cbegin(), lists.cend(), [](auto list) { glDeleteLists(list, 1); });
        lists.clear();
    }

    void CallLists(types::vectorList const &lists)
    {
        std::for_each(lists.cbegin(), lists.cend(), [](auto list){ CallList(list); });
    }
}
