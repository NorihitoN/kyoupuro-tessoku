use proconio::input;

fn main() {
    input! {
        n: usize,
        k: u64,
        a: [u64;n],
    }

    let mut sum = 0;
    let mut j: usize = 0;
    for i in 0..n-1 {
        while j < n && a[j] - a[i] <= k {
            j += 1;
        }
        sum += j - i - 1;
    }
    println!("{}", sum);
}
