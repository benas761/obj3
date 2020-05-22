#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../imports.h"

TEST_CASE( "Stud konstruktoriaus testas") {
    stud a("Jonas Jonaitis 9 2 4 10 2"), b("Vardenis Pavardenis 5");
    REQUIRE( a.getName() == "Jonas" );
    REQUIRE( a.getLname() == "Jonaitis" );
    REQUIRE( a.getAvg() == 3.7f ); // f, nes naudojami float
    REQUIRE( a.getMed() == 3.8f );
    REQUIRE( b.getAvg() == 3 );
}

TEST_CASE( "Operatoriu testas" ) {
    stud a("Jonas Jonaitis 9 2 4 10 2"), b("Vardenis Pavardenis 5"), c("Jonas Jonaitis 10 4 9 2 2"), d = c;
    REQUIRE( (a != b) == true );
    REQUIRE( (a == c) == true );
    REQUIRE( (a > b) == true );
    REQUIRE( (b < c) == true );
    REQUIRE( (b <= c) == true );
    REQUIRE( (b >= c) == false );
    REQUIRE( (a >= c) == true );
    REQUIRE( (a == d) == true );
}

TEST_CASE( "Ivesties ir rinkimo testas" ) {
    vector<stud> a, aa;
    deque<stud> b, bb;
    list<stud> c, cc;
    FileInput(a, "kursiokai.txt");
    FileInput(b, "kursiokai.txt");
    FileInput(c, "kursiokai.txt");
    Pick(a, aa); Pick(b, bb); Pick(c, cc);
    sort(a.begin(), a.end(), cmprName);
    sort(aa.begin(), aa.end(), cmprName);
    sort(b.begin(), b.end(), cmprName);
    sort(bb.begin(), bb.end(), cmprName);
    c.sort(cmprName);
    cc.sort(cmprName);
    REQUIRE( a.size()==b.size() );
    REQUIRE( a.size()==c.size() );

    REQUIRE( a.back().getAvg()==b.back().getAvg() );
    REQUIRE( a.back().getAvg()==c.back().getAvg() );

    REQUIRE( aa.front().getMed()==bb.front().getMed() );
    REQUIRE( aa.front().getMed()==cc.front().getMed() );

    REQUIRE( aa.back().getAvg() == 2.89f );
    REQUIRE( c.back().getAvg() == 6.89f );
}
