use proconio::input;
fn main() {
    input! {
        s: String,
    }
    let ans = usize::from_str_radix(&s, 2).unwrap();
    println!("{}", ans);
}