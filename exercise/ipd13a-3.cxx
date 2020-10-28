#include "ipd13a-3.hxx"

/* 13.a.1
 * What is C++
 * C++ adds many other things than C without slowing things down, which is good for game programming and others.
 *
 * Pros

 * Built-in data types is supported in C.
 * Built-in & user-defined data types is supported in C++.
 *
 * Function and operator overloading is not supported in C.
 * Function and operator overloading is supported by C++.
 *
 * Namespace features are not present inside the C.
 * Namespace is used by C++, which avoid name collisions.
 *
 *13.a.2
 * Header file used by C is stdio.h.
 * Header file used by C++ is iostream.h.
 *
 * scanf() and printf() functions are used for input/output in C.
 * cin and cout are used for input/output in C++.
 *
 * * C provides malloc() and calloc() functions for dynamic memory allocation,
 * and free() for memory de-allocation.
 * C++ provides new operator for memory allocation (won't get a null pointer back from the new)
 * and delete operator for memory de-allocation.
 *
 * Automatic C++ Way: Vector
 *
 */

namespace ipd {

/*
 * Since we aren't in a header here, this Using-declaration only
 * affects this file. For more on Using-declarations, see
 * <https://en.cppreference.com/w/cpp/language/using_declaration>
 *
 * (You can K-click the link above in CLion to open it in a browse,
 * where for X is Command on Mac, and [let me know] on Windows.)
 */
    using std::swap;


    bool sort_refs(int &a, int &b) {
        if (a > b) {
            swap(a, b);
            return true;
        }
        return false;
    }

    bool sort_refs(int &a, int &b, int &c) {

        bool changed = sort_refs(a, c);

        bool changed2 = sort_refs(a, b);

        bool changed3 = sort_refs(b, c);

        return (changed || changed2 || changed3);


    }
}

