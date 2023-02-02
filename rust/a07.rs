use proconio::input;
fn main() {
    input! {
        d: usize,
        n: usize,
        lr: [(usize,usize); n],
    }
    let mut a = vec![0; 100009];
    for i in 1..=n {
        a[lr[i - 1].0] += 1;
        a[lr[i - 1].1 + 1] -= 1;
    }
    let mut s = vec![0; 100009];
    for i in 1..=d {
        s[i] = s[i - 1] + a[i];
        println!("{}", s[i]);
    }
}
