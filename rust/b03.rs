use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut is_found: bool = false;
    for i in 0..n {
        for j in (i + 1)..n {
            for k in (j + 1)..n {
                if a[i] + a[j] + a[k] == 1000 {
                    is_found = true;
                }
            }
        }
    }
    if is_found {
        println!("Yes")
    } else {
        println!("No")
    }
}
