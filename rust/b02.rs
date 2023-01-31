use proconio::input;

fn main() {
    input! {
        a: u32,
        b: u32,
    }
    let mut is_found: bool = false;
    for i in a..=b {
        if 100 % i == 0 {
            is_found = true;
            break;
        }
    }
    if is_found {
        println!("Yes")
    } else {
        println!("No")
    }
}
