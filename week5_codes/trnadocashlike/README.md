## Foundry

**Foundry is a blazing fast, portable and modular toolkit for Ethereum application development written in Rust.**

Foundry consists of:

-   **Forge**: Ethereum testing framework (like Truffle, Hardhat and DappTools).
-   **Cast**: Swiss army knife for interacting with EVM smart contracts, sending transactions and getting chain data.
-   **Anvil**: Local Ethereum node, akin to Ganache, Hardhat Network.
-   **Chisel**: Fast, utilitarian, and verbose solidity REPL.

## Documentation

https://book.getfoundry.sh/

## Usage

### Build

```shell
$ forge build
```

### Test

```shell
$ forge test
```

### Format

```shell
$ forge fmt
```

### Gas Snapshots

```shell
$ forge snapshot
```

### Anvil

```shell
$ anvil
```

### Cast

```shell
$ cast <subcommand>
```

### Help

```shell
$ forge --help
$ anvil --help
$ cast --help
```


# Circom

[https://docs.circom.io/getting-started/installation/](https://docs.circom.io/getting-started/installation/)

## Install
```sh
git clone https://github.com/iden3/circom.git
cd circom
cargo build --release
cargo install --path circom
```

## Install dependencies 
```sh
npm install 
```

## Build
```sh
circom circuits/onetime_note.circom --r1cs --wasm --sym -l . -l node_modules -o build
```

# ワンタイムノート回路のテスト

## テストデータの生成と検証手順

以下の手順でワンタイムノート回路のテストと検証を行います。

1. **回路のビルド**
   ```sh
   mkdir -p build
   circom circuits/onetime_note.circom --r1cs --wasm --sym -l . -l node_modules -o build
   ```

2. **テストデータの生成**
   ```sh
   pnpm run gen
   ```

4. **証明の生成と検証**
   ```sh
   # 証明鍵の生成（テスト用、実運用環境では信頼できるセットアップが必要）
   pnpm run setup-keys
   
   # 証明の生成
   # 最初にwitness（回路の実行証跡）を計算
   pnpm run generate-witness
   
   # 次に証明を生成
   pnpm run generate-proof
   
   # 証明の検証
   pnpm verify-proof
   ```

5. **結果の解釈**
   
   検証が成功した場合、以下のような出力が表示されます：
   ```
   [INFO]  snarkJS: OK!
   ```
   
   これは、生成したテストデータが有効で、回路の制約を正しく満たしていることを示します。

### テストケースの追加

様々なシナリオでテストを行うために、以下のようなテストケースを追加することも可能です：

1. 金額が一致しない場合（sumIn != sumOut）
2. 無効なNullifier値の場合
3. 無効なマークルパスの場合
4. 無効な署名の場合

各テストケースでは、`generate_test_data.js`を修正して異なる値を生成し、それぞれの場合で検証が失敗することを確認します。

## Solidity 検証コントラクトのデプロイ

生成した ZKP の検証を行う Solidity コントラクト（Groth16Verifier）をデプロイするための手順です。

### 1. 検証コントラクトの生成（すでに存在する場合はスキップ）

```sh
pnpm run generate-contract
```

### 2. 環境変数の設定

`.env.dev` ファイルに必要な環境変数を設定します。

1. プロジェクトルートディレクトリに `.env` ファイルを作成します：

```sh
cp .env.dev .env
```

2. `.env` ファイルを編集して、以下の値を設定します：

```
# Sepolia テストネット用 RPC URL（Infura、Alchemy などから取得）
SEPOLIA_RPC_URL=https://sepolia.infura.io/v3/YOUR_INFURA_API_KEY

# デプロイに使用するウォレットの秘密鍵（0x プレフィックスなし）
PRIVATE_KEY=your_wallet_private_key_here

# コントラクト検証用の Etherscan API キー
ETHERSCAN_API_KEY=your_etherscan_api_key_here
```

### 3. デプロイスクリプトの実行

以下のコマンドを使用して、Groth16Verifier コントラクトをデプロイできます：

#### ローカル開発環境（Anvil）へのデプロイ

別のターミナルで Anvil を起動し、ローカルノードを実行します：

```sh
anvil
```

#### Sepolia テストネットへのデプロイ

```sh
forge script script/DeployVerifier.s.sol --rpc-url $SEPOLIA_RPC_URL --private-key $PRIVATE_KEY --broadcast --verify
```

### 4. デプロイ結果の確認

デプロイが成功すると、コンソールに以下のような情報が表示されます：

```
Deploying Groth16Verifier contract...
Groth16Verifier deployed at: 0x...（コントラクトアドレス）
```

このアドレスを使用して、Etherscan（Sepoliaの場合は https://sepolia.etherscan.io ）でコントラクトを確認できます。

### 検証テスト
以下のパラメータを入力する
_pA: `[0x118e0f7dbe09cda367245d89c469ad5f74ffe961cb797e629386f21ce3c83997, 0x1be567ddc47fa171b470e0cbb77f545c8a6c640b9c76b746cef57dcfd0b8c909]`

_pB: `[[0x274e08ac3854c4da809802d9b61a670493af064700601d35ab8d35d2077cd946, 0x24ff3ecdcf3cafdf3efc4f10fe68376b39430ed3cdba31e9d43d0efd44000427],[0x0fc1b82e84eaaa27c63fd3551e6cfd391751cf5c4ed5cf952bc8d5d097a11f9d, 0x1a17ea4bf98c32b71a717308e58dfa8c5ac11b28b4e7ca290603afcd76f1fd25]]`

_pC: `[0x03105bd5756bd4323938850c4b2bdc3fe2112e420331fccc5525c45fe0641105, 0x1b25f06524fd0e8f9ca42a14706738855e33795501d5d72c2894ae9739027d0d]`

_pubSignals: `[0x0000000000000000000000000000000000000000000000000000000000000000,0x29a9d5368dc4c97d27b27e355a18e052573dd0fc0b309d2e8804c17fbcb6a5f8,0x0cfe45f81828d8c4bd167d78dd153ddc99d364562a5d45aa7737ab40372ae7f9,0x22837a3a73cf53f14d9d83119af850b25ad2112d5827e26e5aba0bd21ae36d3d,0x1276a0ef85a25adfdfa4c9eee0f25994fabe5d675ae7635fe458b8d680afbe8a,0x1e1b961c7e9132f4258aeb9f47d282ea34a25a09ecec5550238c02387273d281,0x0e52acab53913e3ab7ef283c97112cd2dea028462e0d745c29009a17862188ad,0x0de9bee8504f1c247be43390b330fcac05b8b40f035778b886a742d603957e57]`

### 注意事項

- デプロイ前にテストネットの ETH が十分にあることを確認してください。
- Sepolia テストネットの ETH は、フォーセットから入手できます。
- 秘密鍵は `.env` ファイルに保存されますが、このファイルは決して Git リポジトリにコミットしないでください。
