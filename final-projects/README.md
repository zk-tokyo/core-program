# Final Project

皆さんには、このプログラムの最終成果物として、各々でテーマを設定し、期間中にプロジェクトとして取り組んでいただきます。基本的には各自（各チーム）で進めていただきますが、毎週のホワイトボードセッションの時間にもチームフォーミングやアイデア練り、プロジェクト内容の壁打ち等の時間を設けているので、そちらも積極的に活用してみてください。

## プロジェクト内容の制約

プロジェクトのテーマや内容は基本的に自由ですが、以下の条件を満たしている必要があります。

- 最終成果物が**オープンソース**であること
- **プロジェクトプロポーザル**が書かれていること（詳細は[下記セクション](#プロジェクトの進め方)を参照）

## プロジェクトの進め方

> [!IMPORTANT]
> 以下のステップ1~4はすべて、[はじめに作成したフォークリポジトリー](../README.md/#4-課題プロジェクトの提出方法)の中で行います。

### 1. プロジェクトプロポーザルの作成

[テンプレート](./project_proposal_template.md)をコピーして、プロポーザルを作成しましょう。プロポーザルはチームで1つ作成するため、この段階でチームが決められることが理想的です。個人で進めたい場合や、とりあえず進めておきたい際は、チーム決めは後回しにしてそのまま進めていただいて問題ありません。

```sh
# cd into `final-projects` directory
$ cd final-projects
# copy template & rename it with your PROJECT_NAME
$ cp project_proposal_template.md project_proposal_{PROJECT_NAME}.md
```

### 2. プロジェクトブランチの作成

プロジェクト名（あるいはチーム名）を決め、プロジェクト用のブランチを作成しましょう。これ以降は、作成したブランチ上でプロジェクトを進めていただきます。

```sh
# create & checkout to a new branch
$ git checkout -b final-project/{PROJECT_NAME}
# push branch to remote
$ git push origin final-project/{PROJECT_NAME}
```

### 3. プロジェクトディレクトリの作成

プロジェクト名（あるいはチーム名）で、プロジェクトディレクトリを `final-projects` 配下に作成しましょう。

```sh
# make a new directory with your PROJECT_NAME
$ mkdir {PROJECT_NAME}
```

プロジェクトディレクトリが作成できたら、1で作成したプロポーザルをその中へ移動しましょう。

```sh
$ mv project_proposal_{PROJECT_NAME} {PROJECT_NAME}
```

### 4. プロジェクトの進行

3で作成したプロジェクトディレクトリの中で、プロジェクトを進めましょう。

### 5. プロジェクトの提出

プロジェクトブランチから `main` ブランチへ向けて、PRを作成してプロジェクトを提出しましょう。**PRテンプレートは、`final projects` を選択してください。**
