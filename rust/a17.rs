use proconio::input;
use std::{cmp::min, vec};

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


    let mut path = vec![n-1];
    let mut pos = n-1;
    while pos > 0  {
        if dp[pos] == dp[pos-1] + a[pos-1] { pos -= 1; }
        else { pos -= 2;}
        path.push(pos);
    }
    path.reverse();
    println!("{}", path.len());
    println!("{}", path.iter().map(|x| (x+1).to_string()).collect::<Vec<_>>().join(" "));

    // println!("{}", dp.last().unwrap());
}
