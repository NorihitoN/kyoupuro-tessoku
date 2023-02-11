use proconio::input;

fn main() {
    input! {
        n: usize,
        k: u64,
        a: [u64;n],
        b: [u64;n],
        c: [u64;n],
        d: [u64;n],
    }

    let mut p = vec![];
    let mut q = vec![];
    for a_val in &a {
        for b_val in &b {
            p.push(a_val + b_val);
        }
    }
    for c_val in &c {
        for d_val in &d {
            q.push(c_val + d_val);
        }
    }
    q.sort();
    let mut ans = "No".to_string();
    for pp in p {
        if let Ok(_) = q.binary_search(&(k - pp)) {
                ans = "Yes".to_string();
        }
    }
    println!("{}", ans);
}
