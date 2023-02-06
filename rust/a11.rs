use proconio::input;

fn main() {
    input! {
        n: usize,
        x: u32,
        a: [u32;n],
    }
    let mut l = 0;
    let mut r = n - 1;

    while l < r {
        let m = (l + r) / 2;
        if x <= a[m] {
            r = m;
        } else {
            l = m + 1;
        }
    }
    println!("{}", l+1);
}
