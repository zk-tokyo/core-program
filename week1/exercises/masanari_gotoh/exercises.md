1. zkSNARKの具体的なユースケースを自分で一つ考えて、p.23にある方式のうち
どれを使うべきか理由とともに説明してください  
- 
1. 実用化されているZKアプリケーションを一つ見つけて、以下の3つのドメインに何が
採用されているのかURLとともに答えてください  
-  Zcash:https://z.cash/ (github: https://github.com/zcash/zcash)
    - ドメイン固有言語: PlonkishArithmetization
    -  SNARKフレンドリな形式 Chips
    -  バックエンド証明器 halo2
1. (+α問題) 2で採用されている方法にはどんな特徴があるか説明してください  
- trusted setupを必要としない。
- rustによって実装されている。  
- 通常のplonkよりも算術ゲートに柔軟性がある。