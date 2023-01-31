use proconio::input;

fn main() {
    input! {
        n: u32,
        k: u32,
        p: [u32; n],
        q: [u32; n],
    }
    let mut is_found: bool = false;
    for i in p.iter() {
        for j in q.iter() {
            if i + j == k {
                is_found = true;
            }
        }
    }
    if is_found {
        println!("Yes")
    } else {
        println!("No")
    }
}
