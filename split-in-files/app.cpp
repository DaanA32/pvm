// In foo.cpp


// In bar.cpp


// In baz.cpp
void baz()
{
    bar(1, 2);
}

// In qux.cpp
void qux(bool b)
{
    foo(1);
    bar(5, 6);

    if (b)
        qux(false);
}

// In app.cpp
int main()
{
    foo(5);
    qux(false);
}