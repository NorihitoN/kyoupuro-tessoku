use proconio::input;
fn main() {
    input! {
        h: usize,
        w: usize,
        x: [[u32;w];h],
        q: usize,
    }
    let mut z = vec![vec![0; w + 1]; h + 1];
    for i in 1..=h {
        for j in 1..=w {
            z[i][j] = z[i][j - 1] + x[i - 1][j - 1];
        }
    }
    for j in 1..=w {
        for i in 1..=h {
            z[i][j] += z[i - 1][j];
        }
    }

    for _ in 1..=q {
        input! {
            a: usize,
            b: usize,
            c: usize,
            d: usize,
        }
        println!("{}", z[c][d] - z[a - 1][d] - z[c][b - 1] + z[a - 1][b - 1])
    }
}
