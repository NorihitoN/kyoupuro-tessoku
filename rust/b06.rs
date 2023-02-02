use proconio::input;
fn main() {
    input! {
        n: usize,
        a: [usize; n],
        q: usize,
        lr: [(usize,usize); q],
    }
    let mut win = vec![0];
    let mut lose = vec![0];
    for i in 0..n {
        if a[i] == 1 {
            win.push(win[i] + 1);
            lose.push(lose[i]);
        } else {
            win.push(win[i]);
            lose.push(lose[i] + 1);
        }
    }

    for (l, r) in lr {
        let wl = (win[r] - win[l - 1]) - (lose[r] - lose[l - 1]);
        if wl > 0 {
            println!("win");
        } else if wl < 0 {
            println!("lose");
        } else {
            println!("draw");
        }
    }
}