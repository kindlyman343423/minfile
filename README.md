# MINFILE

It is a cli application to generate min file size easily.

## DEPENDENCIES

* gcc compiler
* bash shell

## PREQUESTIES

* Must have little CLI usage experience (Beginner level)
* Running bash scripts
* Compiling and running c programs

## USAGE

Run the binary in case of linux as

```bash
./minfile filename.css
```

You can see new file of name `filename.min.css`. Open that file and see the output.

**Please copy this binary on same location as that of your file which you want to convert**

## BUILD

### LINUX

For build for your linux distro use

```bash
bash build.bash
```

Now you have fresh binary in bin folder for your distro

## FILETYPE SUPPORT

* css
* html (partially supported)
* js (partially supported)
* c (partially supported)

## TEST OUR APPLICATION

Feel cool because you can test our application also. For that follow below steps

* Open terminal or cmd in repo root folder
* Go to test directory

```bash
cd test
```

* Now start usage by

```bash
./minfile test.css
```

## RESULTS

### CSS

It will convert `test.css to test.min.css`

```css
p {
    background: brown;
}
```

You will get resultant file as test.min.css

```css
p{background:brown;}
```