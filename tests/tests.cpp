#include "../catch/catch.hpp"
#include "../graph.h"

TEST_CASE("All vertices added to graph") {
    Graph graph("samplePA.txt");
    REQUIRE(graph.getTotalVertices() == 17);
}
