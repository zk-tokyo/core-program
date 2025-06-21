// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import {Script, console2} from "../lib/forge-std/src/Script.sol";
import {Groth16Verifier} from "../src/Verifier.sol";

contract VerifyProofScript is Script {
    function run() public {
        // Load environment variables
        address verifierAddress;
        try vm.envAddress("VERIFIER_ADDRESS") {
            verifierAddress = vm.envAddress("VERIFIER_ADDRESS");
        } catch {
            // Default to the known deployed address if env var is not set
            verifierAddress = 0xEc3213b7690AC84aa0e1d95f7344d49A2085d32F;
        }

        // Start broadcast for any state changes (not needed here but required for Script)
        vm.startBroadcast();

        // Use existing deployed verifier contract instead of deploying a new one
        Groth16Verifier verifier = Groth16Verifier(verifierAddress);
        console2.log("Using deployed Groth16Verifier at:", verifierAddress);

        // Parameters provided in the task
        uint256[2] memory _pA = [
            0x118e0f7dbe09cda367245d89c469ad5f74ffe961cb797e629386f21ce3c83997,
            0x1be567ddc47fa171b470e0cbb77f545c8a6c640b9c76b746cef57dcfd0b8c909
        ];

        uint256[2][2] memory _pB = [
            [
                0x274e08ac3854c4da809802d9b61a670493af064700601d35ab8d35d2077cd946,
                0x24ff3ecdcf3cafdf3efc4f10fe68376b39430ed3cdba31e9d43d0efd44000427
            ],
            [
                0x0fc1b82e84eaaa27c63fd3551e6cfd391751cf5c4ed5cf952bc8d5d097a11f9d,
                0x1a17ea4bf98c32b71a717308e58dfa8c5ac11b28b4e7ca290603afcd76f1fd25
            ]
        ];

        uint256[2] memory _pC = [
            0x03105bd5756bd4323938850c4b2bdc3fe2112e420331fccc5525c45fe0641105,
            0x1b25f06524fd0e8f9ca42a14706738855e33795501d5d72c2894ae9739027d0d
        ];

        uint256[8] memory _pubSignals = [
            0x0000000000000000000000000000000000000000000000000000000000000000,
            0x29a9d5368dc4c97d27b27e355a18e052573dd0fc0b309d2e8804c17fbcb6a5f8,
            0x0cfe45f81828d8c4bd167d78dd153ddc99d364562a5d45aa7737ab40372ae7f9,
            0x22837a3a73cf53f14d9d83119af850b25ad2112d5827e26e5aba0bd21ae36d3d,
            0x1276a0ef85a25adfdfa4c9eee0f25994fabe5d675ae7635fe458b8d680afbe8a,
            0x1e1b961c7e9132f4258aeb9f47d282ea34a25a09ecec5550238c02387273d281,
            0x0e52acab53913e3ab7ef283c97112cd2dea028462e0d745c29009a17862188ad,
            0x0de9bee8504f1c247be43390b330fcac05b8b40f035778b886a742d603957e57
        ];

        // Verify that the proof is valid
        bool result = verifier.verifyProof(_pA, _pB, _pC, _pubSignals);

        // Print the result
        console2.log("Proof verification result:", result);

        // Ensure the verification succeeded
        require(result, "Proof verification should return true");

        vm.stopBroadcast();
    }
}
