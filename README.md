Lyrabar integration/staging tree
================================

http://lyrabar.com/

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2014 Vertcoin Developers
Copyright (c) 2015 Lyrabar Developers

What is Lyrabar?
----------------

Lyrabar is rock solid, rare cryptocoin bar using Lyra2RE as a proof-of-work algorithm.

 - 2.5 minute block targets
 - 1971000 total LYB
 - 5 coins per block
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

Will be developed further.

Compiling
---------

Dependencies needed are exactly same as in Vertcoin;

	sudo apt-get install automake autoconf libtool build-essential libgmp-dev

Also, we need to install the secp256k1 module:
	
	cd /opt
	git clone https://github.com/bitcoin/secp256k1
	cd secp256k1
	sudo ./autogen.sh
	sudo ./configure
	sudo make
	sudo make install (optional)

Update LD cache so the system knows about the freshly installed secp256k1 existence,

	sudo ld-config

Makefiles for the core code are in `src/`. To compile and run them, type in Lyrabar directory:

    cd src
	./autogen.sh (if building from git repository)
	./configure
	make -f makefile.unix
	strip lyrabard
	
To run freshly compiled daemon, type:
	
	./lyrabard

Makefiles for the Qt client are in `src/`. To compile and run them:

	cd src
	./autogen.sh (if building from git repository)
	./configure
    make -f makefile.linux-mingw
	strip lyrabar-qt
	
To run freshly compiled Qt client, type:
	
    ./lyrabar-qt

