## 1. ゴール

Core Programはゼロ知識証明の理論と実装の理解を促し、Ethereumエコシステムや実社会にコミットする技術者を養成する学習プログラムです。このプログラムは今年で3回目となり、主催はzk Tokyoが行います。また、Ethereum FoundationのZKETのバックアップを受けながら進めていきます。

最終的に参加者の皆さんには成果物を提出していただきます。想定される成果物としては以下のようなものが挙げられます。

- オリジナルのzk dAppsを実装する
- zkに関するOSSに貢献する
- ライブラリを実装する

また、9月に開催される[ETH Tokyo](https://ethtokyo.org/)ではハッカソンが催されます。Core Programの成果物をこのハッカソンに提出することが奨励されます。

どのような最終成果物を出すかは参加者自身が決めることができます。最終週の初めにアンケートや面談を実施し、どのようなものを作りたいか伺うので、各自で目標設定を行なってください。

なお、最終成果物は9/15までに提出していただきますので、期間中に実装できる範囲で計画してください。

## 2. スケジュール

このプログラムではオンライン学習をベースにオンサイトでの演習やゲストスピーカーによる公演なども予定しています。6週間と短い期間なので、事前にweek0としてゼロ知識証明の理解に必要な数学的基礎を身につけていただくために、教材を用意しております。

|  | オンライン | オンサイト | ゲストスピーカー |
| --- | --- | --- | --- |
| week0(7/28~8/2) | 数学的基礎	 | なし | なし |
| week1(7/28~8/2) | [ゼロ知識証明入門](https://drive.google.com/drive/folders/1iH6mtAOkWp9AXTnpKf47pQyZmvwx38_w?usp=sharing) | ホワイトボードセッション1	 | TBD |
| week2(8/4~8/9) | コミットメントスキーム・PLONK | ホワイトボードセッション2	 | なし |
| week3(8/12~8/16) | [Groth16](https://drive.google.com/drive/folders/1GluJltqnuLZLSwH6Htu7KtfeCMeYlNX4?usp=drive_link) | ホワイトボードセッション3	 | TBD |
| week4(8/18~8/23) | [zk-STARK](https://drive.google.com/drive/folders/1oi6bDyubh9IQqEA0-XmvCrISlQ5rxBrR?usp=drive_link) | ホワイトボードセッション4	 | なし |
| week5(8/25~8/30) | [zkのライブラリやアプリ実装、OSSの紹介](https://drive.google.com/drive/folders/1Uu-iBUOr0ssVA_6K6nDPljmxOJo1mIfU?usp=drive_link) | Tornado-cashの実装演習	 | TBD |
| week6(9/1~9/6) | 成果物の準備期間 | ハッカソンアイデアの壁打ち会	 | なし |
| extra |  | 反省会・打ち上げ	 | なし |

オンラインの学習・演習は各自オンデマンドに行っていただきます。ホワイトボードセッションはオンサイトで行いますので、必ず[現地](https://maps.app.goo.gl/C78Ctg9HfwhkXRiV9)にお越しください。**10:00~16:00**を想定していますが、その週の演習内容によって終了時間が前後することを予めご了承ください。

例えばweek1のスケジュールは以下のようになります。

1. 6/28までに教材が共有される
2. 7/28~8/1まで自主学習する
3. 8/1までにオンライン演習を提出する
4. 8/2にオンサイト演習に取り組む
5. 8/8までにオンライン演習のレビューが返ってくる

ゲストスピーカによる公演は現在調整中です。日時やオンライン・オンサイトなどの決定は追って連絡いたします。なお、Core ProgramのスケジュールはGoogle Calendarで共有いたします。

[](https://calendar.google.com/calendar/u/1?cid=ZjI4ZjhmOWY4NTMzMzJmM2FiNDEzZjQ3Y2ZhZTFkOWMyNzNiN2UwOWQ4OGUwZDM5ZTRmYzQ3MDZiNWVkZTg2NkBncm91cC5jYWxlbmRhci5nb29nbGUuY29t)

## 3. カリキュラムと学習教材

6週間のうちweek 1 から week 4までは理論、week5, 6は応用にフォーカスします。

学習教材は各自がオンデマンド形式で学べるように、スライドと解説動画を用意しています。

[Untitled](https://www.notion.so/2144cf0b61e48047aa72d55f0d361f13?pvs=21)

教材は作成途中であり、その週の月曜日までには共有します。ステータスは上記のテーブルを確認ください。また、より深く学びたい人や最終成果物のヒント欲しい人に向けて補助教材を作成したので、ご覧ください。

[補助教材](https://www.notion.so/20e4cf0b61e480f58208f62296fe2871?pvs=21)

### 3.1 オンライン演習

各週の理解を促進するためにスライドに演習問題が付随しています。

ホワイトボードセッションの前日までに提出してください。

演習提出先に各週の回答テンプレートを用意しているので、これをコピーし、ファイル名「week{n}_自分の名前.md」として提出してください。[数式](https://docs.github.com/ja/get-started/writing-on-github/working-with-advanced-formatting/writing-mathematical-expressions)や[コードブロック](https://docs.github.com/ja/get-started/writing-on-github/working-with-advanced-formatting/creating-and-highlighting-code-blocks)を埋め込むことができるため、ファイル形式をマークダウンに統一します。

week 5など、プログラムの実装が必要な演習については個人のGithub上にレポジトリを作り、そのURLを提出してください。

提出された演習問題は各週の担当者が評価し、次の週の金曜日までにレビューを返します。

もしフォーマットなど疑問があれば演習の詳細な形式は週によって異なる場合があるので、各週の担当者の指示を仰いでください

### 3.2 オンサイト演習

オンサイトでも演習を行います。これはホワイトボードセッションと呼びます。

オンラインでの演習とは違い、グループでのディスカッションがメインです。議論や図示を用いて参加者どうしの理解度を高めるとともに、参加者同士の交流を促す目的があります。

全体のフローは以下のようになります。

1. 15人の参加者を3グループに分ける
2. 各グループはホワイトボードを使って学び合いながら演習問題を解く
3. 最終的にグループとして一つの回答を作成する
4. 各週の担当者がその場でレビューする

また、グループは毎週シャッフルします。

ホワイトボードセッションのために何か準備する必要ありませんが、その週の学習内容をもとに出題するので、しっかり教材を確認しておいてください。

ちなみに、ホワイトボードセッションは[ZK Podcast](https://zeroknowledge.fm/)が提供しているコンテンツからインスパイアを受けたものです。もし興味があればこちらもご覧ください。

[ZK Whiteboard Sessions - S1](https://www.youtube.com/playlist?list=PLj80z0cJm8QErn3akRcqvxUsyXWC81OGq)

## 4. メンター

メンターとしてCore Programを支えてくれる方々を紹介します。

| Discord名 | 役割 | 自己紹介 |
| --- | --- | --- |
| shouki | week 0 | hgoe |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |
|  |  |  |

教材について疑問があれば[Discord](https://discord.gg/DPj88upb)にて気軽に質問してください。その週の担当メンターにメンションすると気づきやすいと思います。

Core ProgramをバックアップしてくれているEthereum FoundationのZKETの方々を紹介します。

## 5. QA

<details><summary>Q. プログラムを修了するための条件はありますか？</summary>
    A. 特にありません。ただし、6週間のカリキュラムを通して技術力を培うように構成しているので、毎週の演習問題と最終成果物は必ず提出してください
</details>

<details><summary>Q. プログラムを修了するための条件はありますか？</summary>
    A. 特に注意書きがない限り問題ありません
</details>

<details><summary>Q. オンサイトの参加は必須ですか？</summary>
    A. はい。遠方の方や特別な理由がない限り毎週現地に赴いていただきます。電車の都合などで遅刻する場合は必ず連絡をしてください。
</details>

<details><summary>Q. 演習問題でChat GPTなどAI ツールを使っても良いですか？</summary>
    A. はい。
</details>

<details><summary>Q. 演習問題でChat GPTなどAI ツールを使っても良いですか？</summary>
    A. はい。
</details>

<details><summary>Q. 最終成果物を誰かと共同で作成することは可能ですか？</summary>
    A. 可能です。メンターとしてもチーム形成を促したいと思います。
</details>

<details><summary>Q. 最終成果物は実装以外でも大丈夫ですか？</summary>
    A. 基本的に実装を想定しています
</details>

<details><summary>
Q. 過去のCore Programについて教えてください
</summary>
https://github.com/ethereum/zket-core-program

</details>
<details><summary>Q. ハッカソンの参加は必須ですか？</summary>;    いいえ。</details>
