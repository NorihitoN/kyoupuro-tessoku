use proconio::input;

fn main() {
    input! {
        n: usize,
    }

    for i in range(0, 10) {
        println!("{}", i * n);
    }
}
