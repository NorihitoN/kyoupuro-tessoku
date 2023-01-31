use proconio::input;
fn main() {
    input! {
        mut n: u32,
    }
    let mut ans = 0;
    let mut i = 0;
    while n > 0 {
        ans += (n % 10) * 1 << i;
        i += 1;
        n /= 10;
    }
    println!("{}", ans);
}