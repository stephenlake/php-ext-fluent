namespace Fluent;

class Str
{
    private str;
    private ignoreCase;

    public function __construct($s = "")
    {
        let this->str = $s;
        let this->ignoreCase = false;
    }

    public function startsWith($needle)
    {
        var $length = strlen($needle);

        if (this->ignoreCase) {
            return substr(strtolower(this->str), 0, $length) === strtolower($needle);
        }

        return (substr(this->str, 0, $length) === $needle);
    }

    public function endsWith($needle)
    {
        var $length = strlen($needle);

        if (this->ignoreCase) {
            return substr(strtolower(this->str), -$length) === strtolower($needle);
        }

        if ($length == 0) {
            return true;
        }

        return (substr(this->str, -$length) === $needle);
    }

    public function length() {
      return strlen(this->str);
    }

    public function splitBy($separator = " ") {
      var $result = explode($separator, this->str);

      return $result;
    }

    public function split($separator = " ") {
      return $this->splitBy($separator);
    }

    public function explode($separator = " ") {
      return $this->splitBy($separator);
    }

    public function ignoreCase() {
       let this->ignoreCase = true;

       return this;
    }

    public function ignoringCase() {
        return $this->ignoreCase();
    }

    public static function create($str) {
        return new Str($str);
    }

    public static function from($str) {
        return self::create($str);
    }

    public static function of($str) {
        return self::create($str);
    }

    public static function random($length = 16)
    {
        string stringA = "";
        int size = 0;
        var bytes = 0;

        while strlen(stringA) < $length {
            let size = $length - strlen(stringA);
            let bytes = random_bytes($length);
            let stringA .= substr(str_replace(["/", "+", "="], "", base64_encode(bytes)), 0, size);
        }

        return stringA;
    }

    public function text() {
        return $this->__toString();
    }

    public function toString() {
        return $this->__toString();
    }

    public function __toString() {
        return this->str;
    }
}
