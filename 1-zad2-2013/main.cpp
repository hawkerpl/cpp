#include <iostream>

using namespace std;

int main()
{
        struct A { virtual  void a() {}; static void s() {}; };    // 1 musz� by� zrobione definicje
        struct B : public A { virtual void b() {}; };              // 2

        const A a; const A & b = B();                              // 3 nie mo�na zrobi� referencji do obiektu nie const
    //    a.a();                                                     // 4 funkcja nie jest const
        a.s();                                                     // 5 dzia�a, bo jest static
    //    a.b();                                                     // 6 nie ma takiej funkcji w A
   //     b.a();                                                     // 7 funkcja nie jest const
        b.s();                                                     // 8 dzia�a, bo jest static
        /*
         * [13:13] <advisor_> b to referencja na A
			[13:14] <advisor_> wi�c nie ma dost�pu do B
			[13:14] <advisor_> a nie bo nie jest const
         */
        b.b();
}
