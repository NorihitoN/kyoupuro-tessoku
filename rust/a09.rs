use proconio::input;
fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
    }
    let mut x = vec![vec![0; w + 1]; h + 1];
    let mut z = vec![vec![0; w + 1]; h + 1];
    for _ in 0..n {
        input! {
            a: usize,
            b: usize,
            c: usize,
            d: usize,
        }
        x[a - 1][b - 1] += 1;
        x[c][b - 1] -= 1;
        x[a - 1][d] -= 1;
        x[c][d] += 1;
    }
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

    for i in 1..=h {
        for j in 1..=w {
            if j >= 2 {
                print!(" ");
            }
            print!("{}", z[i][j]);
        }
        println!();
    }
}
