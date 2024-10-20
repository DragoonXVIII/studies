#ifndef EVEN_H_INCLUDED
#define EVEN_H_INCLUDED
class Even
{
    private:
        int divider;
    public:
        Even(int divider);

        bool operator( )(int x);
};
#endif // EVEN_H_INCLUDED
