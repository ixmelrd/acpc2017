# coding: utf-8
#! /usr/bin/env ruby

# tests内で ruby cheker.rb と実行してください
# 上の階層の SOLUTION ファイルがあるディレクトリのソースコードをコンパイルし、実行します
# 入力ファイルとしては、このディレクトリ内の *.in が使われるので
# 必要に応じて ./generator をこの場で実行してください

infs = Dir.glob("*.in").sort

acs = []
was = []

dirs = Dir.glob("../*/")
dirs.each { |dir|
  next unless Dir.glob(File.join(dir, 'SOLUTION')).first
  src = Dir.glob(File.join(dir, 'main.*')).first
  next unless src
  if system "g++ -std=c++11 #{src} -o solver"
    p src
    ac = true
    infs.each { |inf|
      command = "./reactive ./solver < #{inf}"
      res = `#{command}`
      res = res.split("\n").last
      if res && res == 'AC'
        puts "%-16s | AC" % inf
      else
        puts "%-16s | WA!!!!!!!!!!!!!!" % inf
        p res
        ac = false
        break
      end
    }
    if ac
      acs << src
    else
      was << src
    end
  end
  puts
}

puts "AC: #{acs.inspect}"
puts "WA: #{was.inspect}"
