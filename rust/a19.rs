use proconio::input;
use std::cmp::max;

fn main() {
    input! {
        n: usize,
        w: usize,
        wv: [(usize,u64);n],
    }
    let mut dp = vec![vec![0; w + 1]; n + 1];

    for nn in 1..=n {
        for ww in 0..=w {
            let (w_nn, v_nn) = wv[nn - 1];
            if ww < w_nn {
                dp[nn][ww] = dp[nn - 1][ww];
            } else {
                dp[nn][ww] = max(dp[nn - 1][ww - w_nn] + v_nn, dp[nn - 1][ww]);
            }
        }
    }
    println!("{}", dp[n][w]);
}
