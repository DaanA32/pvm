#include <iostream>

#define SWITCH_STRING(string)   auto _switch_string_ = string;
#define STRING_CASE(case)       if(_switch_string_ == #case)
#define STRING_ELSE             else

int foo(std::string tag)
{
    SWITCH_STRING(tag)
    {
        STRING_CASE(a)
        {
            return 1;
        }

        STRING_CASE(b)
        {
            return 2;
        }

        STRING_CASE(abc)
        {
            return 3;
        }

        STRING_ELSE
        {
            return -1;
        }
    }
}