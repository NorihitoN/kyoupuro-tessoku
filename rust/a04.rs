use proconio::input;
fn main() {
    input! {
        n: u32,
    }
    for x in (0..=9).rev() {
        print!("{}", (n / 2_u32.pow(x)) % 2);
    }
}