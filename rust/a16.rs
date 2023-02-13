use proconio::input;
use std::cmp::min;

fn main() {
    input! {
        n: usize,
        a: [u64;n-1],
        b: [u64;n-2],
    }
    let mut dp = vec![];
    dp.push(0);
    dp.push(a[0]);
    for i in 2..n {
        dp.push(min(dp[i - 1] + a[i - 1], dp[i - 2] + b[i - 2]));
    }
    println!("{}", dp.last().unwrap());
}
