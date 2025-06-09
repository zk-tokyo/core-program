// SPDX-License-Identifier: GPL-3.0
pragma solidity >=0.7.0 <0.9.0;

import {Script, console} from "../lib/forge-std/src/Script.sol";
import {Groth16Verifier} from "../src/Verifier.sol";

contract DeployVerifierScript is Script {
    Groth16Verifier public verifier;

    function setUp() public {}

    function run() public {
        console.log("Deploying Groth16Verifier contract...");

        vm.startBroadcast();

        verifier = new Groth16Verifier();
        console.log("Groth16Verifier deployed at:", address(verifier));

        vm.stopBroadcast();
    }
}
