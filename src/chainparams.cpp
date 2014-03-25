// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"
#include <boost/assign/list_of.hpp>
using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0xbce2d77e, 0x6baa73c4, 0xbce2d4e4
};

class CMainParams : public CChainParams {
public:
    CMainParams() {

        pchMessageStart[0] = 0x2f;
        pchMessageStart[1] = 0x23;
        pchMessageStart[2] = 0x2c;
        pchMessageStart[3] = 0x25;
        vAlertPubKey = ParseHex("04fc710d2840001733f1efc96e7e7ec73bfa114384460be236bfe14ba927e84e257f024ab7d3c63e1207028d88cda00d09e8d84484d60782af7146c544f0d298f2");
        nDefaultPort = 3557;
        nRPCPort = 3556;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyHalvingInterval = 0;

        // Build the genesis block.
        const char* pszTimestamp = "Daily Times NG - 23 Mar 2014 - Nigeria And Namibia To Build Joint Oil Refinery";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(2);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 41360026320 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04e1b3d6725f4fdd7853ef70f7cc12b1694a4abfeaf3b9656ac8c11364c03b581af0568c95d5e29d38a218d5d1574dd4cc1359912eb6f76978eb5b5edd74793468") << OP_CHECKSIG;
        txNew.vout[1].nValue = 2640001680 * COIN;
        txNew.vout[1].scriptPubKey = CScript() << ParseHex("04715925407bbe765987f70f31f6ce63391d7258557a48cc5cf02f96b6436a1eb1d9cb6afb9c4955a09ce7bb785eb2ca916df28fb016a4247a9b5b2e089584c950") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1395625935;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 1171094;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x0000056f9d5ca022a6c906f09a37dfb41fc83414f7aa33f2c4eed37969a77c6f"));
        assert(genesis.hashMerkleRoot == uint256("0xaf403a7989b1aa075f571dabbfe3fbab4bd69a2a1ceba43006e220a9595df445"));

        vSeeds.push_back(CDNSSeedData("seed1.nigeriacoin.org", "seed1.nigeriacoin.org"));
        vSeeds.push_back(CDNSSeedData("seed2.nigeriacoin.org", "seed2.nigeriacoin.org"));
        vSeeds.push_back(CDNSSeedData("seed3.nigeriacoin.org", "seed3.nigeriacoin.org"));
        
        base58Prefixes[PUBKEY_ADDRESS] = list_of(53);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(12);
        base58Prefixes[SECRET_KEY] =     list_of(181);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB3)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAE)(0xE4);

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x07;
        pchMessageStart[1] = 0xa1;
        pchMessageStart[2] = 0x53;
        pchMessageStart[3] = 0x03;
        vAlertPubKey = ParseHex("04d6e8ce1d1b5b221cbf6f7b69f9b8a840525a3d15e8646c6c566dc9518520b63d9fd6552e3a9674f42a02b8cbfe60f54d5018d51b0f702a51857c5677c7e24a10");
        nDefaultPort = 13557;
        nRPCPort = 13556;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits = bnProofOfWorkLimit.GetCompact();
        genesis.nTime = 1395625949;
        genesis.nNonce = 621587444;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x000002dafaae08116bd746e66e07df8f03e0538da1ae9d1014d19b33314978f6"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("testnet-seed1", "seed3.nigeriacoin.org"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(55);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(188);
        base58Prefixes[SECRET_KEY]     = list_of(183);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x86)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x84)(0x94);
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0x0f;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0x5a;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1395402789;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 10;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 19559;
        strDataDir = "regtest";
        
        /*while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }
        printf("%s\n", hashGenesisBlock.ToString().c_str());
        printf("%d\n", genesis.nNonce);*/
        
        assert(hashGenesisBlock == uint256("0x436cd99b716af165fae597e2271aa8bb3dbbf91a75ea4eb00799da7491a814dd"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
