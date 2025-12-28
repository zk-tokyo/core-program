#[derive(Debug)]
pub struct Result {
    pub d: i32,
    pub x: i32,
    pub y: i32,
}

pub fn ext_euclid(a: i32, b: i32) -> Result {
    if b == 0 {
        let res = Result { d: a, x: 1, y: 0 };
        println!(
            "d: {0}, x: {1}, y: {2}, a: {3}, b: {4} [{3} * {1} + {4} * {2} = {0}]",
            res.d, res.x, res.y, a, b,
        );
        return res;
    } else {
        let Result { d, x: x1, y: y1 } = ext_euclid(b, a % b);
        let res = Result {
            d,
            x: y1,
            y: x1 - (a / b) * y1,
        };
        println!(
            "d: {0}, x: {1}, y: {2}, a: {3}, b: {4} [{3} * {1} + {4} * {2} = {0}]",
            res.d, res.x, res.y, a, b,
        );
        return res;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_ext_euclid() {
        let Result { d, x, y } = ext_euclid(30, 12);
        assert_eq!(d, 6);
        assert_eq!(x, 1);
        assert_eq!(y, -2);
    }
    #[test]
    fn test_ext_euclid_2() {
        let Result { d, x, y } = ext_euclid(35, 13);
        assert_eq!(d, 1);
        assert_eq!(x, 3);
        assert_eq!(y, -8);
    }
    #[test]
    fn test_ext_euclid_zero() {
        let Result { d, x, y } = ext_euclid(0, 5);
        assert_eq!(d, 5);
        assert_eq!(x, 0);
        assert_eq!(y, 1);
    }
    #[test]
    fn test_ext_euclid_negative() {
        let Result { d, x, y } = ext_euclid(-30, 12);
        assert_eq!(d, -6);
        assert_eq!(x, 1);
        assert_eq!(y, 2);
    }
    #[test]
    fn test_ext_euclid_large_numbers() {
        let Result { d, x, y } = ext_euclid(123456, 789012);
        assert_eq!(d, 12);
        assert_eq!(x, 22963);
        assert_eq!(y, -3593);
    }
    #[test]
    fn test_ext_euclid_identity() {
        let Result { d, x, y } = ext_euclid(1, 1);
        assert_eq!(d, 1);
        assert_eq!(x, 0);
        assert_eq!(y, 1);
    }
    #[test]
    fn test_ext_euclid_identity_zero() {
        let Result { d, x, y } = ext_euclid(0, 0);
        assert_eq!(d, 0);
        assert_eq!(x, 1);
        assert_eq!(y, 0);
    }
}
