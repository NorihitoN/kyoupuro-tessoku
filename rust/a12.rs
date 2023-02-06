use proconio::input;

fn main() {
    input! {
        n: usize,
        k: u64,
        a: [u64;n],
    }
    let mut l = 1;
    let mut r = 1_000_000_000;

    while l < r {
        let m = (l + r) / 2;
        if check(m, k, &a) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    println!("{}",l);
}

fn check(m: u64, k: u64, a: &[u64]) -> bool {
    let mut sum = 0;
    for val in a {
        sum += m / val;
    }
    k <= sum
}
