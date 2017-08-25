
int f();

int g()
{
    return 100;
}

int main()
{
    return !( 100==f() );
}
