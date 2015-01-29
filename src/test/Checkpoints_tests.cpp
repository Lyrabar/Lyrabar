//
// Unit tests for block-chain checkpoints
//
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include "../checkpoints.h"
#include "../util.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity)
{
    uint256 p0 = uint256("0xgenesisblockhash");
//    uint256 p210237 = uint256("0x500kthblockhash");
    BOOST_CHECK(Checkpoints::CheckBlock(0, p0));
//   BOOST_CHECK(Checkpoints::CheckBlock(100000, p100000)); //100kth block


    // Wrong hashes at checkpoints should fail:
	BOOST_CHECK(!Checkpoints::CheckBlock(0, p0));
//    BOOST_CHECK(!Checkpoints::CheckBlock(0, p500000)); //add checkpoint at last block
//    BOOST_CHECK(!Checkpoints::CheckBlock(500000, p0)); //add checkpoint at last block

    // ... but any hash not at a checkpoint should succeed:
    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p0));
//    BOOST_CHECK(Checkpoints::CheckBlock(0+1, p500000)); //add checkpoint at last block
//    BOOST_CHECK(Checkpoints::CheckBlock(500000+1, p0)); //add checkpoint at last block

    BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 500000);
}

BOOST_AUTO_TEST_SUITE_END()
