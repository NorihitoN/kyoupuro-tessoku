use proconio::input;
use std::cmp::max;

fn main() {
    input! {
        n: usize,
        a: [u32;n],
        d: usize,
        lr: [(usize,usize); d],
    }
    let mut x = vec![0; n];
    let mut y = vec![0; n];
    x[0] = a[0];
    y[n - 1] = a[n - 1];
    for i in 1..n {
        x[i] = max(x[i - 1], a[i]);
    }
    for i in (0..(n - 1)).rev() {
        y[i] = max(y[i + 1], a[i]);
    }

    for i in 0..d {
        println!("{}", max(x[lr[i].0 - 2], y[lr[i].1]));
    }
}
