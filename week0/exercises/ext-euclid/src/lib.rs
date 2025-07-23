#[derive(Debug)]
pub struct Result {
    pub d: i32,
    pub x: i32,
    pub y: i32,
    pub a: i32,
    pub b: i32,
}
impl std::fmt::Display for Result {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{} * {} + {} * {} = {}",
            self.a, self.x, self.b, self.y, self.d
        )
    }
}

pub fn ext_euclid(a: i32, b: i32) -> Result {
    if b == 0 {
        let res = Result {
            d: a,
            x: 1,
            y: 0,
            a,
            b,
        };
        println!("{:?} [{}]", res, res);
        return res;
    } else {
        let Result {
            d,
            x: x1,
            y: y1,
            a: a1,
            b: b1,
        } = ext_euclid(b, a % b);
        let res = Result {
            d,
            x: y1,
            y: x1 - (a / b) * y1,
            a,
            b,
        };
        println!("{:?} [{}]", res, res);
        return res;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_ext_euclid() {
        let Result { d, x, y, a, b } = ext_euclid(30, 12);
        assert_eq!(d, 6);
        assert_eq!(x, 1);
        assert_eq!(y, -2);
        assert_eq!(a, 30);
        assert_eq!(b, 12);
    }
    #[test]
    fn test_ext_euclid_2() {
        let Result { d, x, y, a, b } = ext_euclid(35, 13);
        assert_eq!(d, 1);
        assert_eq!(x, 3);
        assert_eq!(y, -8);
        assert_eq!(a, 35);
        assert_eq!(b, 13);
    }
    #[test]
    fn test_ext_euclid_zero() {
        let Result { d, x, y, a, b } = ext_euclid(0, 5);
        assert_eq!(d, 5);
        assert_eq!(x, 0);
        assert_eq!(y, 1);
        assert_eq!(a, 0);
        assert_eq!(b, 5);
    }
    #[test]
    fn test_ext_euclid_negative() {
        let Result { d, x, y, a, b } = ext_euclid(-30, 12);
        assert_eq!(d, -6);
        assert_eq!(x, 1);
        assert_eq!(y, 2);
        assert_eq!(a, -30);
        assert_eq!(b, 12);
    }
    #[test]
    fn test_ext_euclid_large_numbers() {
        let Result { d, x, y, a, b } = ext_euclid(123456, 789012);
        assert_eq!(d, 12);
        assert_eq!(x, 22963);
        assert_eq!(y, -3593);
        assert_eq!(a, 123456);
        assert_eq!(b, 789012);
    }
    #[test]
    fn test_ext_euclid_identity() {
        let Result { d, x, y, a, b } = ext_euclid(1, 1);
        assert_eq!(d, 1);
        assert_eq!(x, 0);
        assert_eq!(y, 1);
        assert_eq!(a, 1);
        assert_eq!(b, 1);
    }
    #[test]
    fn test_ext_euclid_identity_zero() {
        let Result { d, x, y, a, b } = ext_euclid(0, 0);
        assert_eq!(d, 0);
        assert_eq!(x, 1);
        assert_eq!(y, 0);
        assert_eq!(a, 0);
        assert_eq!(b, 0);
    }
}
