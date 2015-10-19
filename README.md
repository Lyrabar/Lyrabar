Lyrabar
=======

http://lyrabar.com/

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2014 Vertcoin Developers
Copyright (c) 2015 Lyrabar Developers

What is Lyrabar?
----------------

Lyrabar is rock solid, rare cryptocoin bar using Lyra2REv2 as a proof-of-work algorithm.

 - Lyra2RE(v2) as algorithm
 - 2.5 minute block targets
 - 1971000 total LYB
 - PoW subsidy: 5 coins per block
 - Block reward will half at blocks 210240, 420480, 630720 (one year between each)
 - Last PoW block is 840960
 - Difficulty retargeting with Kimoto's Gravity Well
 - Stealth addresses (experimental, use at own risk)


Ports for client connectivity
-----------------------------
 
Mainnet RPC 4047
Mainnet P2P 4046

Testnet RPC 14047
Testnet P2P 14046

License
-------

Lyrabar is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

0.9.1.0 includes:
Change to Lyra2REv2 algorithm at block 160000

Compiling
---------

Dependencies needed to build the wallet (use sudo if needed)

	apt-get install git automake autoconf libtool build-essential
	apt-get install libminiupnpc-dev libqt4-dev libqrencode-dev libboost-all-dev libgmp-dev libssl-dev
	
Download the BerkeleyDB 4.8 source package (recommended to check the sha256sum just in case)

	wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
	echo '12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef  db-4.8.30.NC.tar.gz' | sha256sum -c

Extract the BerkeleyDB source package and build it:

	tar -xvf db-4.8.30.NC.tar.gz
	cd db-4.8.30.NC/build_unix
	mkdir -p build
	BDB_PREFIX=$(pwd)/build
	../dist/configure --disable-shared --enable-cxx --with-pic --prefix=$BDB_PREFIX
	make install
	cd ../..

Also, we need to install the secp256k1 module:
	
	cd /opt
	git clone https://github.com/bitcoin/secp256k1
	cd secp256k1
	git checkout 4c63780710351ffcc52341497e3ca0e518fbad79
	./autogen.sh
	./configure
	make
	make install

Update the LD cache to tell the system about the freshly installed secp256k1 existence,

	ldconfig (or ld-config)

Makefiles for the wallet source code are in `src/`. To build the wallet, type in Lyrabar directory:

	cd src
	./autogen.sh (if building from git repository)
	./configure CPPFLAGS="-I${BDB_PREFIX}/include/ -O2" LDFLAGS="-L${BDB_PREFIX}/lib/"
	make -f makefile.unix
	strip lyrabard
	
To run freshly compiled daemon, type:
	
	./lyrabard

Makefiles for the Qt client are in `src/`. To compile and run them:

	cd src
	./autogen.sh (if building from git repository)
	./configure CPPFLAGS="-I${BDB_PREFIX}/include/ -O2" LDFLAGS="-L${BDB_PREFIX}/lib/"
    	make -f makefile.linux-mingw
	strip lyrabar-qt
	
To run freshly compiled Qt client, type:
	
    ./lyrabar-qt

