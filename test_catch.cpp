#define CATCH_CONFIG_MAIN

#include "Catch/include/catch.hpp"
#include <cstring>
#include "pileGen.hpp"


TEST_CASE("Constructeur par defaut") {
   PileGen<int> p; // cela implique que par defaut la capacite de la pile n'est pas nulle => pas d exception

   CHECK(  p.isEmpty() );
   CHECK(  0 == p.size() );
}

TEST_CASE("Exceptions de mauvaise construction") {

   REQUIRE_THROWS_AS( PileGen<int>(-1).isEmpty(), std::invalid_argument );
   REQUIRE_THROWS_AS( PileGen<int>( 0).isEmpty(), std::invalid_argument );

}

TEST_CASE("Exception pile vide") {

   REQUIRE_THROWS_AS( PileGen<int>().pop(), std::invalid_argument );

}

TEST_CASE("Live pile") {
    PileGen<int> p(10);

    CHECK(  p.isEmpty() );
    CHECK(  0 == p.size() );

    p.push(5);

    CHECK( !p.isEmpty() );
    CHECK( 1 == p.size() );
    CHECK( 5 == p.top() );

    p.push(2);
    p.push(1);

    CHECK( 3 == p.size() );
    CHECK( 1 == p.top() );

    p.pop();

    CHECK( 2 == p.size() );
    CHECK( 2 == p.top() );

    p.pop();
    p.pop();

    CHECK( 0 == p.size() );

}
