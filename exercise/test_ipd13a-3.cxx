#include "ipd13a-3.hxx"
#include <catch.hxx>

using ipd::sort_refs;


TEST_CASE("sort_refs(int& a, int& b, int& c)")
{
    int a, b, c;

    SECTION ("a > b > c ") {
        a = 5;
        b = 4;
        c = 3;

        CHECK (sort_refs(a,b,c));
        CHECK (a == 3);
        CHECK (c == 5);

        CHECK (sort_refs(c,b,a));
        CHECK (c == 3);
        CHECK (a == 5);
    }

    SECTION ("a > b") {
        a = 5;
        b = 4;
        c = 6;

        CHECK (sort_refs(a,b,c));
        CHECK (a == 4);
        CHECK (b == 5);

        std::swap(a, b);

        CHECK (b == 4);
        CHECK (a == 5);
    }

    SECTION ("a == b") {
        a = 4;
        c = 4;
        b = 4;

        CHECK_FALSE (sort_refs(a,b,c));
        CHECK (a == 4);
        CHECK (b == 4);

        CHECK_FALSE (sort_refs(b, a ,c));
        CHECK (a == 4);
        CHECK (b == 4);
    }

    SECTION ("b > c") {
        a = 2;
        b = 5;
        c = 3;

        CHECK (sort_refs(a, b, c));
        CHECK (b == 3);
        CHECK (c == 5);

        CHECK (sort_refs(a, c, b));
        CHECK (c == 3);
        CHECK (b == 5);
    }

    SECTION ("b > c & b < a") {
        a = 7;
        b = 5;
        c = 3;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 3);
        CHECK (b == 5);
        CHECK (c == 7);

        CHECK (sort_refs(a, c, b));
        CHECK (a == 3);
        CHECK (c == 5);
        CHECK (b == 7);
    }


    SECTION ("b > c & b < a") {
        a = 4;
        b = 5;
        c = 3;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 3);
        CHECK (b == 4);
        CHECK (c == 5);

        CHECK (sort_refs(a, c, b));
        CHECK (a == 3);
        CHECK (c == 4);
        CHECK (b == 5);
    }



}


TEST_CASE("sort_refs(float& a, float& b, float& c)")
{
    float a, b, c;

    SECTION ("a > c") {
        a = 5.1f;
        b = 4.1f;
        c = 3.1f;

        CHECK (sort_refs(a,b,c));
        CHECK (a == 3.1f);
        CHECK (c == 5.1f);

        CHECK (sort_refs(c,b,a));
        CHECK (c == 3.1f);
        CHECK (a == 5.1f);
    }

    SECTION ("a > b") {
        a = 5.1f;
        b = 4.1f;
        c = 6.1f;
        CHECK (sort_refs(a,b,c));
        CHECK (a == 4.1f);
        CHECK (b == 5.1f);

        std::swap(a, b);

        CHECK (b == 4.1f);
        CHECK (a == 5.1f);
    }

    SECTION ("a == b") {
        a = 4.2f;
        c = 4.2f;
        b = 4.2f;

        CHECK_FALSE (sort_refs(a,b,c));
        CHECK (a == 4.2f);
        CHECK (b == 4.2f);

        CHECK_FALSE (sort_refs(b, a ,c));
        CHECK (a == 4.2f);
        CHECK (b == 4.2f);
    }

    SECTION ("b > c") {
        a = 2.3f;
        b = 5.3f;
        c = 3.3f;

        CHECK (sort_refs(a, b, c));
        CHECK (b == 3.3f);
        CHECK (c == 5.3f);

        CHECK (sort_refs(a, c, b));
        CHECK (c == 3.3f);
        CHECK (b == 5.3f);
    }

    SECTION ("b > c & b < a") {
        a = 7.4f;
        b = 5.4f;
        c = 3.4f;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 3.4f);
        CHECK (b == 5.4f);
        CHECK (c == 7.4f);

        CHECK (sort_refs(a, c, b));
        CHECK (a == 3.4f);
        CHECK (c == 5.4f);
        CHECK (b == 7.4f);
    }
}


TEST_CASE ("sort_refs(int& a, int& b)")
{
    int a, b;

    SECTION ("a > b") {
        a = 5;
        b = 3;

        CHECK (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        CHECK (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a < b") {
        a = 3;
        b = 5;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        std::swap(a, b);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a == b") {
        a = 4;
        b = 4;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 4);
        CHECK (b == 4);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (a == 4);
        CHECK (b == 4);
    }
}
