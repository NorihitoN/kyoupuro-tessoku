use proconio::input;
fn main() {
    input! {
        n: i32,
        k: i32,
    }
    let mut count = 0;
    for i in 1..=n {
        for j in 1..=n {
            let s = k - i - j;
            if s >= 1 && s <= n {
                count += 1;
            }
        }
    }
    print!("{}", count);
}
