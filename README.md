<!-- <div align=center >
<h1>42cursus - minitalk</h1>
<img src="https://raw.githubusercontent.com/viruskizz/viruskizz-myutils/main/ft_printf_badge.png" alt="printft_badge" />
</div> -->
# 42cursus - minitalk

>
> This project is learn about linux signal communicate programe and compuster process id
> you can learn these subject in example section (Thai version)
>
> <a href="exmaple">Minitalk in Nutshell</a>
>

## Project Information

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### My Features

- server convert bit signal to byte
- client recieve signal and write 0 or 1
- 40 microsecond for English character
- 50 microsecond for UTF-8

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

## Usages

1. Clone project

```sh
git clone https://github.com/viruskizz/42bangkok-minitalk.git
```

2. Compile programe with Makefile

```sh
make
```

3. start `server`

```sh
./server
```

4. run `client` with additional arguments `ppid` and `text`

```sh
./client 1234 ABCD
```

5. run `client` with test file

```sh
./client 1234 "$(cat test/eng.txt)"
```

## Credit

README template
- [`hanshazairi`](https://github.com/hanshazairi)

Thank you to our friend
- [`nnakarac`](https://profile.intra.42.fr/users/nnakarac/)
- [`spoolpra`](https://profile.intra.42.fr/users/spoolpra/)