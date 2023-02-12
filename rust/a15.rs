use std::collections::HashSet;

use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [u64;n],
    }
    let mut b = a
        .clone()
        .into_iter()
        .collect::<HashSet<_>>()
        .into_iter()
        .collect::<Vec<_>>();
    b.sort();

    let mut z = vec![0; n];
    for i in 0..n {
        let pos = b.binary_search(&a[i]).unwrap();
        z[i] = pos + 1;
    }
    println!("{}", z.iter().map(|x| format!("{}", x)).collect::<Vec<_>>().join(" "));
}
